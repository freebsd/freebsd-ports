#
# A rewrite-influenced bug was introduced in 4.31.
# http://www.exim.org/pipermail/exim-users/Week-of-Mon-20040419/070387.html
#
*** src/verify.c  Thu Apr 15 09:27:01 2004
--- verify.c	Wed Apr 21 16:28:18 2004
***************
*** 758,764 ****
  address_item *addr_succeed = NULL;
  uschar *ko_prefix, *cr;
  uschar *address = vaddr->address;
! uschar *save_sender = sender_address;
  uschar null_sender[] = { 0 };             /* Ensure writeable memory */

  /* Set up a prefix and suffix for error message which allow us to use the same
--- 758,764 ----
  address_item *addr_succeed = NULL;
  uschar *ko_prefix, *cr;
  uschar *address = vaddr->address;
! uschar *save_sender;
  uschar null_sender[] = { 0 };             /* Ensure writeable memory */

  /* Set up a prefix and suffix for error message which allow us to use the same
***************
*** 816,825 ****

  /* If the address was rewritten to <> no verification can be done, and we have
  to return OK. This rewriting is permitted only for sender addresses; for other
! addresses, such rewriting faile. */

  if (address[0] == 0) return OK;

  /* Update the address structure with the possibly qualified and rewritten
  address. Set it up as the starting address on the chain of new addresses. */

--- 816,830 ----

  /* If the address was rewritten to <> no verification can be done, and we have
  to return OK. This rewriting is permitted only for sender addresses; for other
! addresses, such rewriting fails. */

  if (address[0] == 0) return OK;

+ /* Save a copy of the sender address for re-instating if we change it to <>
+ while verifying a sender address (a nice bit of self-reference there). */
+
+ save_sender = sender_address;
+
  /* Update the address structure with the possibly qualified and rewritten
  address. Set it up as the starting address on the chain of new addresses. */

***************
*** 898,904 ****
      if (!is_recipient) sender_address = null_sender;
      rc = route_address(addr, &addr_local, &addr_remote, &addr_new,
        &addr_succeed, verify_type);
!     sender_address = save_sender;
      }

    /* If routing an address succeeded, set the flag that remembers, for use when
--- 903,909 ----
      if (!is_recipient) sender_address = null_sender;
      rc = route_address(addr, &addr_local, &addr_remote, &addr_new,
        &addr_succeed, verify_type);
!     sender_address = save_sender;     /* Put back the real sender */
      }

    /* If routing an address succeeded, set the flag that remembers, for use when
