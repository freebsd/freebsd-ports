# $FreeBSD$

SRCS_M	=	main.c pop3d.c auth.c plcat.c mydaemon.c listen.c sig.c log.c conf.c checkip.c auth.h checkip.h conf.h const.h listen.h log.h mydaemon.h plcat.h pop3d.h sig.h
SRCS_B	=	bent.c

OBJS_M	=	${SRCS_M:N*.h:R:S/$/.o/}
OBJS_B	=	${SRCS_B:N*.h:R:S/$/.o/}

LDFLAGS	+=	-lcrypt

MISSEY	=	missey
BENT	=	bent

all:		$(MISSEY) $(BENT)
$(MISSEY):	$(OBJS_M)
	$(CC) ${CFLAGS} -o $(MISSEY) $(OBJS_M) $(LDFLAGS)
$(BENT):	$(OBJS_B)
	$(CC) ${CFLAGS} ${PTHREAD_CFLAGS} -o $(BENT) $(SRCS_B) ${PTHREAD_LIBS}
install:
	@${MKDIR} -p $(PREFIX)/etc/missey/
	${INSTALL_DATA} $(WRKSRC)/pop3d.conf $(PREFIX)/etc/missey/pop3d.conf-dist
	${INSTALL_PROGRAM} $(WRKSRC)/$(MISSEY) $(PREFIX)/sbin/$(MISSEY)
	${INSTALL_PROGRAM} $(WRKSRC)/$(BENT) $(PREFIX)/sbin/$(BENT)

