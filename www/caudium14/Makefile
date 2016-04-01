# Created by: kiwi@oav.net
# $FreeBSD$

PORTNAME=	caudium14
PORTVERSION=	${DISTVERSION}.${PIKEVERSION}
DISTVERSION=	1.4.18
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://caudium.googlecode.com/files/
DISTNAME=	Caudium-${DISTVERSION}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Free webserver based on the Roxen Challenger 1.3 code base

BUILD_DEPENDS=	pike78:lang/pike78
LIB_DEPENDS=	libsablot.so:textproc/sablotron
RUN_DEPENDS=	lsof:sysutils/lsof

USES=		gmake tar:bzip2

# Pike version included from lang/pike78
SUB_LIST+=	PIKEVERSION=${PIKEVERSION}
PLIST_SUB+=	PIKEVERSION=${PIKEVERSION}

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--without-debug --with-PiXSL --prefix=${PREFIX} \
		--with-pike=${LOCALBASE}/pike/${PIKEVERSION}/bin/pike
CPPFLAGS+=	-I${WRKSRC}/src/cmods
INSTALL_TARGET=	install_alt

DOCSDIR=	${PREFIX}/share/doc/caudium

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -i '' -e '1s:@PIKE@:${LOCALBASE}/bin/pike:' \
		${WRKSRC}/server/start-caudium.in
	@${REINPLACE_CMD} -i '' -e '1s:bin/pike:${LOCALBASE}/bin/pike:' \
		${WRKSRC}/server/protocols/tetris.pike
	@${SED} -e 's:@CAUDIUM_SERVERDIR@:${PREFIX}/caudium/server:' \
		-e 's:^#############$$:${ECHO} "$${caudium_enable}" | ${EGREP} -iq "^yes|^true" || exit:' \
		-e 's:/tmp/caudium_pid:/var/run/caudium.pid:' \
		-e '/flags=--with-threads/s:^# ::' \
		-e 's:-www:-${WWWOWN}:' \
		${WRKSRC}/tools/caudium-rc_script.in > ${WRKDIR}/caudium
	@${REINPLACE_CMD} -e 's,/share/man/,/man/,' \
		-e 's,/etc/caudium,${PREFIX}&,' ${WRKSRC}/Makefile.in

post-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/caudium ${STAGEDIR}${PREFIX}/etc/rc.d/

.include <bsd.port.pre.mk>

post-configure:
.for m in Mhash PCRE PiXSL UltraLog _Caudium
	@${REINPLACE_CMD} -e 's/^LD=.*/LD= ld -shared/' \
		-e 's/^LIBGCC=.*/LIBGCC=/' \
		${WRKSRC}/src/cmods/$m/Makefile
. if ${ARCH} != i386
	@${REINPLACE_CMD} -e '/^CFLAGS=/s/$$/ -fPIC/' \
		${WRKSRC}/src/cmods/$m/Makefile
. endif
.endfor

.include "../../lang/pike78/Makefile.common"
.include <bsd.port.post.mk>
