#pragma once

#include <glib.h>

#include "axc.h"
#include "libomemo.h"
#include "libomemo_crypto.h"

/**
 * The OMEMO crypto provider settings.
 */
static const omemo_crypto_provider crypto = {
    .random_bytes_func = omemo_default_crypto_random_bytes,
    .aes_gcm_encrypt_func = omemo_default_crypto_aes_gcm_encrypt,
    .aes_gcm_decrypt_func = omemo_default_crypto_aes_gcm_decrypt
};

/**
 * Encrypts a data buffer, usually the omemo symmetric key, using axolotl.
 * Assumes a valid session already exists.
 *
 * @param recipient_addr_p Pointer to the lurch_addr of the recipient.
 * @param key_p Pointer to the key data.
 * @param key_len Length of the key data.
 * @param axc_ctx_p Pointer to the axc_context to use.
 * @param key_ct_pp Will point to a pointer to an axc_buf containing the key ciphertext on success.
 * @return 0 on success, negative on error
 */
int lurch_crypto_encrypt_key(const lurch_addr * recipient_addr_p,
                             const uint8_t * key_p,
                             size_t key_len,
                             axc_context * axc_ctx_p,
                             axc_buf ** key_ct_buf_pp);

/**
 * For each of the recipients, encrypts the symmetric key using the existing axc session,
 * then adds it to the omemo message.
 * If the session does not exist, the recipient is skipped.
 *
 * @param om_msg_p Pointer to the omemo message.
 * @param addr_l_p Pointer to the head of a list of the intended recipients' lurch_addrs.
 * @param no_sess_l_p Pointer to the head of a list of the subset of the inteded recipients for which a session was not yet
 *      established when the message was written.
 * @param axc_ctx_p Pointer to the axc_context to use.
 * @return 0 on success, negative on error.
 */
int lurch_crypto_encrypt_msg_for_addrs(omemo_message * om_msg_p, GList * addr_l_p, GList * no_sess_l_p, axc_context * axc_ctx_p);
