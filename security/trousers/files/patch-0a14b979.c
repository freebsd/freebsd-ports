commit 0a14b979064052d3263054488602fba3bf97883b
Author: Jerry Snitselaar <jsnitsel@redhat.com>
Date:   Wed Jan 16 14:00:43 2019 -0700

    trousers: clean up use after free in Transport_TerminateHandle
    
    Clean up possible use after free. The value of the handles pointer
    may change, but if it doesn't then free is being called twice on
    the same address.
    
    Signed-off-by: Jerry Snitselaar <jsnitsel@redhat.com>
    Signed-off-by: Debora Velarde Babb <debora@linux.ibm.com>

diff --git src/tcs/tcs_evlog_imaem.c src/tcs/tcs_evlog_imaem.c
index d158330..33af283 100644
--- src/tcs/tcs_evlog_imaem.c
+++ src/tcs/tcs_evlog_imaem.c
@@ -259,6 +259,7 @@ ima_get_entry(FILE *handle, UINT32 pcr_index, UINT32 *num, TSS_PCR_EVENT **ppEve
 				if (event->rgbPcrValue == NULL) {
 					LogError("malloc of %d bytes failed.", 20);
 					free(event);
+					event = NULL;
 					result = TCSERR(TSS_E_OUTOFMEMORY);
 					goto done;
 				}
