PORTNAME=	tlci
DISTVERSION=	0.1.0.2
CATEGORIES=	misc

MAINTAINER=	nsonack@outlook.com
COMMENT=	Tiny Lambda Calculus interpreter
WWW=		https://gitlab.com/herrhotzenplotz/tlci

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITLAB=	yes
GL_ACCOUNT=	herrhotzenplotz
GL_COMMIT=	4a3dd51a872f36a513f06efa475922259dee91f1

PLIST_FILES=	${PREFIX}/bin/tlci \
		${PREFIX}/man/man8/tlci.8.gz

.include <bsd.port.options.mk>

#post-patch:
#.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
#	@${REINPLACE_CMD} -e 's|^CFLAGS\+=|CFLAGS\+=	-Wno-error=strict-prototypes |g' \
#		${WRKSRC}/Makefile
#.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/tlci

.include <bsd.port.mk>
