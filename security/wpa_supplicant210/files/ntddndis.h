#ifndef _NTDDNDIS_H_
#define _NTDDNDIS_H_

/*
 * Fake up some of the Windows type definitions so that the NDIS
 * interface module in wpa_supplicant will build.
 */

#define ULONG uint32_t
#define USHORT uint16_t
#define UCHAR uint8_t
#define LONG int32_t
#define SHORT int16_t
#if __FreeBSD__
#define CHAR char
#else
#define CHAR int8_t
#endif
#define ULONGLONG uint64_t
#define LONGLONG int64_t
#define BOOLEAN uint8_t
typedef void * LPADAPTER;
typedef char * PTSTR;
typedef char * PCHAR;

#define TRUE 1
#define FALSE 0

#define OID_802_3_CURRENT_ADDRESS               0x01010102
#define OID_802_3_MULTICAST_LIST                0x01010103

#endif /* _NTDDNDIS_H_ */
