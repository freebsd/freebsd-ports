/*
 * Client decompression module for the mud client compression protocol.
 * See http://homepages.ihug.co.nz/~icecube/compress/ for more details.
 *
 * mccpDecompress.h - header definitions. #include this in your client code.
 *
 * Oliver Jowett <icecube$ihug.co.nz>. Demangle address as needed.
 *
 * This code is placed in the public domain.
 *
 */

/* Modified: 981203 */

/*
 *
 * mc_state is an opaque type representing the current compression state of
 * a connection. You should include a (mc_state *) in the information you
 * store for a server connection.
 *
 * Initialization / cleanup:
 *
 *   When a connection is initiated, call mudcompress_new, and store the
 *   resulting pointer in your server connection information. This pointer is
 *   used as a handle for all other functions. This does NOT begin compression
 *   - it just initialises various internal structures.
 *
 *   When a connection is terminated, call mudcompress_delete with the handle
 *   to delete all memory allocated by the decompressor for the connection.
 *
 * Reading / writing:
 *
 *   Reading from the server connection must go through the decompressor at
 *   all times. The decompressor handles both negotiation and decompression
 *   transparently - it receives input directly from the server, then provides
 *   the main client code with decompressed data, hiding all protocol details.
 *
 *   When data is received from the mud server, call mudcompress_receive,
 *   passing it the handle for the connection, a pointer to the data read,
 *   and the length of data read. It is VITAL that ALL data read is passed
 *   to the decompressor - including data with embedded NULs!
 *
 *   After mudcompress_receive has been called, call mudcompress_pending() to
 *   see if any decompressed data is available. It returns the number of
 *   bytes pending.
 *
 *   If there is pending data waiting, call mudcompress_get to retrieve it.
 *   This fills up to "size" bytes in the provided buffer "buf", and returns
 *   the number of bytes copied. Your client can now process this data as if
 *   it had been directly read from the server.
 *
 *   Be sure to check mudcompress_pending again after calling mudcompress_get!
 *   Removing some data from the decompress buffer may have allowed the
 *   decompressor to decompress some more data - in which case, you want to
 *   process it immediately, rather than waiting for another read from the
 *   mud server.
 *
 *   Regularly call mudcompress_response. If non-NULL, you need to write the
 *   returned string to the mud server. This is needed when the decompressor
 *   is negotiating compression with the server. When called,
 *   mudcompress_response clears any pending string, so be sure to save its
 *   return value!
 *
 * Status information:
 *
 *   mudcompress_error returns non-0 if there has been a (fatal) decompression
 *   error. In this case, all you can do is tell the user that something went
 *   wrong and close the connection.
 *
 *   mudcompress_stats fills in the two (unsigned long *) values passed, with
 *   the number of compressed bytes read, and the number of bytes that they
 *   decompressed to.
 *
 *   mudcompress_compressing returns non-0 if the connection is currently
 *   using compression.
 *
 */

#ifndef MUDCOMPRESS_H
#define MUDCOMPRESS_H

#ifdef __cplusplus
extern "C" {
#endif

    /*  Opaque handle for a decompressor. Details defined in Compress.c - you
     *  should never need to see them externally.
     */
    struct mc_state_s;
    typedef struct mc_state_s mc_state;

    /*  Create a new decompressor. Return a handle to it.
     */
    mc_state *mudcompress_new(void);

    /*  Deallocate a decompressor and associated data. 'state' is invalid
     *  afterthis call.
     */
    void mudcompress_delete(mc_state *state);

    /*  Perform decompression and negotiation on some received data.
     *  'data' is a pointer to the received data, 'len' is its length.
     */
    void mudcompress_receive(mc_state *state, const char *data, unsigned len);

    /*  Return the number of pending decompressed bytes that can currently
     *  be read by mudcompress_get
     */
    int mudcompress_pending(mc_state *state);

    /*  Return true (non-0) if this decompressor encountered a fatal error.
     */
    int mudcompress_error(mc_state *state);

    /*  Read decompressed data from the decompressor into 'buf', up to a
     *  maximum of 'size' bytes. Returns the number of bytes actually copied.
     */
    int mudcompress_get(mc_state *state, char *buf, int size);

    /*  Set *comp to the number of compressed bytes read, and *uncomp to the
     *  number of bytes they expanded to, for this decompressor.
     */
    void mudcompress_stats(mc_state *state, unsigned long *comp, unsigned long *uncomp);

    /*  Check for a negotiation response. If this returns NULL, no output is
     *  needed. If it returns non-NULL, it points to a NUL-terminated string
     *  that should be sent to the mud server. Calling this function clears
     *  the pending string (so be sure to save the result).
     */
    const char *mudcompress_response(mc_state *state);

    /*  Return true (non-0) if this decompressor has successfully negotiated
     *  compression and is currently performing decompression.
     */
    int mudcompress_compressing(mc_state *state);

#ifdef __cplusplus
}
#endif

#endif
