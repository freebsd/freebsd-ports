# $FreeBSD$

SRCS_M	=	main.c pop3d.c auth.c plcat.c mydaemon.c listen.c mylog.c cfg.c checkip.c
SRCS_B	=	bent.c

OBJS_M	=	${SRCS_M:N*.h:R:S/$/.o/}
OBJS_B	=	${SRCS_B:N*.h:R:S/$/.o/}

LDFLAGS	+=	-lcrypt

MPS	=	mps
BENT	=	bent

all:		$(MPS) $(BENT)
$(MPS):	$(OBJS_M)
	$(CC) ${CFLAGS} -o $(MPS) $(OBJS_M) $(LDFLAGS)
$(BENT):	$(OBJS_B)
	$(CC) ${CFLAGS} ${PTHREAD_CFLAGS} -o $(BENT) $(SRCS_B) ${PTHREAD_LIBS}
install:
	@${MKDIR} -p $(PREFIX)/etc/mps/
	${INSTALL_DATA} $(WRKSRC)/pop3d.conf $(PREFIX)/etc/mps/pop3d.conf-dist
	${INSTALL_PROGRAM} $(WRKSRC)/$(MPS) $(PREFIX)/sbin/$(MPS)
	${INSTALL_PROGRAM} $(WRKSRC)/$(BENT) $(PREFIX)/sbin/$(BENT)

