PORTNAME=	nbsmtp
PORTVERSION=	1.00
PORTREVISION=	4
CATEGORIES=	mail
MASTER_SITES=	LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Simple program for outgoing SMTP delivery

LICENSE=	GPLv2

USES=		cpe ssl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-ipv6 \
		--enable-ssl
CFLAGS+=	-I${OPENSSLINC}
CPPFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}

PLIST_FILES=	bin/nbsmtp \
		share/man/man5/nbsmtprc.5.gz \
		share/man/man8/nbsmtp.8.gz

post-patch:
	${REINPLACE_CMD} -e 's@\(-o nbsmtp\)@$$(LDFLAGS) \1@g'	\
		${WRKSRC}/Makefile.in
	${REINPLACE_CMD} -E '/NULL/s,\(char\) ?,,' \
		${WRKSRC}/main.c ${WRKSRC}/original.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/nbsmtprc.5 ${STAGEDIR}${PREFIX}/share/man/man5
	${INSTALL_MAN} ${WRKSRC}/nbsmtp.8 ${STAGEDIR}${PREFIX}/share/man/man8

.include <bsd.port.mk>
