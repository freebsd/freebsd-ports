# Created by: kiwi@oav.net
# $FreeBSD$

PORTNAME=	caudium14
PORTVERSION=	${DISTVERSION}.${PIKEVERSION}
DISTVERSION=	1.4.18
CATEGORIES=	www
MASTER_SITES=	http://caudium.googlecode.com/files/
DISTNAME=	Caudium-${DISTVERSION}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Free webserver based on the Roxen Challenger 1.3 code base

BUILD_DEPENDS=	pike78:${PORTSDIR}/lang/pike78
LIB_DEPENDS=	libsablot.so:${PORTSDIR}/textproc/sablotron
RUN_DEPENDS=	lsof:${PORTSDIR}/sysutils/lsof

USES=		tar:bzip2 gmake

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
.if ${ARCH} != i386
. for m in Mhash PCRE PiXSL UltraLog _Caudium
	@${REINPLACE_CMD} -e 's/^LD=.*/LD= ld -shared/' \
		-e '/^CFLAGS=/s/$$/ -fPIC/' \
		-e 's/^LIBGCC=.*/LIBGCC=/' \
		${WRKSRC}/src/cmods/$m/Makefile
. endfor
.endif

.include "../../lang/pike78/Makefile.common"
.include <bsd.port.post.mk>
