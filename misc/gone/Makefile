PORTNAME=	gone
PORTVERSION=	1.3.6
CATEGORIES=	misc
MASTER_SITES=	http://www.marcuscom.com/downloads/gone/

MAINTAINER=	marcus@FreeBSD.org
COMMENT=	Terminal locking utility with many improvements over lock(1)

PLIST_FILES=	bin/gone man/man1/gone.1.gz
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	SETUID
SETUID_DESC=	Install gone setuid root for password support

.include <bsd.port.options.mk>

#
# If you would like to be able to use system passwords for gone
# override this with WITH_SETUID=yes in your environment.
# Be aware that setting gone to suid MAY be a security hole.
#
.if ${PORT_OPTIONS:MSETUID}
CONFIGURE_ENV=	with_setuid=yes
.else
CONFIGURE_ENV=	with_setuid=no
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gone ${STAGEDIR}${PREFIX}/bin/gone
	${INSTALL_DATA} ${WRKSRC}/gone.1 ${STAGEDIR}${PREFIX}/man/man1/gone.1

.include <bsd.port.mk>
