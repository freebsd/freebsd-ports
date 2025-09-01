PORTNAME=	tlci
DISTVERSION=	0.1.0.2
PORTREVISION=	1
CATEGORIES=	misc

MAINTAINER=	nsonack@herrhotzenplotz.de
COMMENT=	Tiny Lambda Calculus interpreter
WWW=		https://gitlab.com/herrhotzenplotz/tlci

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITLAB=	yes
GL_ACCOUNT=	herrhotzenplotz
GL_TAGNAME=	4a3dd51a872f36a513f06efa475922259dee91f1

PLIST_FILES=	bin/tlci \
		share/man/man8/tlci.8.gz

.include <bsd.port.options.mk>

#post-patch:
#.if ${OPSYS} == FreeBSD
#	@${REINPLACE_CMD} -e 's|^CFLAGS\+=|CFLAGS\+=	-Wno-error=strict-prototypes |g' \
#		${WRKSRC}/Makefile
#.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tlci ${STAGEDIR}/${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/docs/tlci.8.gz \
		${STAGEDIR}/${PREFIX}/share/man/man8

.include <bsd.port.mk>
