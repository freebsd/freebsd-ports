*** src/os.c.orig	Tue Aug 12 16:39:56 2003
--- src/os.c		Thu Aug 14 15:53:49 2003
***************
*** 659,665 ****
    addrp = &ifreq.V_ifr_addr;

    #else
!   memcpy((char *)&ifreq, cp, len);
    memcpy(addrbuf, (char *)&(ifreq.V_ifr_addr), len - sizeof(ifreq.V_ifr_name));
    addrp = (struct sockaddr *)addrbuf;
    #endif
--- 659,665 ----
    addrp = &ifreq.V_ifr_addr;

    #else
!   memcpy((char *)&ifreq, cp, sizeof(ifreq));
    memcpy(addrbuf, (char *)&(ifreq.V_ifr_addr), len - sizeof(ifreq.V_ifr_name));
    addrp = (struct sockaddr *)addrbuf;
    #endif
