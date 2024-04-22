PORTNAME=	delegate
PORTVERSION=	9.9.13
PORTREVISION=	3
CATEGORIES=	net www
MASTER_SITES=	http://www.delegate.org/anonftp/DeleGate/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	General purpose TCP/IP proxy system
WWW=		http://www.delegate.org/delegate/

LICENSE=	AIST
LICENSE_NAME=	aist
LICENSE_FILE=	${WRKSRC}/LICENSE.txt
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

BROKEN_mips=		fails to build: gmake[1]: [Makefile:116: mkmake.exe] Error 1
BROKEN_mips64=		fails to build: gmake[1]: [Makefile:116: mkmake.exe] Error 1

USES=		compiler:c11 cpe gmake
SUB_FILES=	pkg-message

ADMIN?=		admin@example.com

CFLAGS+=	-x c++ -std=gnu++98
MAKE_JOBS_UNSAFE=yes

PLIST_FILES=	sbin/delegated etc/rc.d/delegated.sh-dist
PORTDOCS=	CHANGES COPYRIGHT HowToDG.html IPv6NOTE.txt \
		Manual.htm jpconv.htm tutor-en.htm tutor-jp.htm

OPTIONS_DEFINE=	DOCS

post-extract:
	@${LN} ${WRKSRC}/CHANGES ${WRKSRC}/COPYRIGHT \
	${WRKSRC}/IPv6NOTE.txt ${WRKSRC}/doc

post-patch:
# Prevent "filesystem was touched prior to 'make install' phase" warning;
# allow unattended (non-interactive) builds
	@${REINPLACE_CMD} -e 's,"$$(XDG)",& DGROOT=${WRKDIR},' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -E '/ADMIN/s,undef,${ADMIN}, ; \
		s,-F(esign|ver),& DGROOT=${WRKDIR},' ${WRKSRC}/src/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/delegated ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${FILESDIR}/delegated.sh \
		${STAGEDIR}${PREFIX}/etc/rc.d/delegated.sh-dist
# Re-sign the executable
	@${MKDIR} ${WRKDIR}/tmp
	@${CP} ${STAGEDIR}${PREFIX}/sbin/delegated ${WRKDIR}/tmp/dg
	@${CHMOD} +w ${STAGEDIR}${PREFIX}/sbin/delegated
	@${WRKDIR}/tmp/dg DGROOT=${WRKDIR}/tmp/ -Fesign -w ${STAGEDIR}${PREFIX}/sbin/delegated
	@${CHMOD} -w ${STAGEDIR}${PREFIX}/sbin/delegated

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/doc/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
