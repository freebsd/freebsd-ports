# Created by: kiwi@oav.net
# $FreeBSD$

PORTNAME=	caudium14
PORTVERSION=	1.4.18
CATEGORIES=	www
MASTER_SITES=	http://caudium.googlecode.com/files/
DISTNAME=	Caudium-${PORTVERSION}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	A free webserver based on the Roxen Challenger 1.3 code base

BUILD_DEPENDS=	pike76:${PORTSDIR}/lang/pike76
LIB_DEPENDS=	sablot:${PORTSDIR}/textproc/sablotron
RUN_DEPENDS=	lsof:${PORTSDIR}/sysutils/lsof

USES=		gmake tar:bzip2

PIKEVERSION=	7.6.112
SUB_LIST+=	PIKEVERSION="${PIKEVERSION}"

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--without-debug --with-PiXSL --prefix=${PREFIX} \
		 --with-pike=${LOCALBASE}/pike/${PIKEVERSION}/bin/pike
CPPFLAGS+=	-I${WRKSRC}/src/cmods

PLIST_SUB+=	PIKEVERSION=${PIKEVERSION}
CONFLICTS+=	caudium12-[0-9]*

NO_STAGE=	yes
post-patch:
	@${SED} -e 's:@CAUDIUM_SERVERDIR@:${PREFIX}/caudium/server:' \
		-e 's:^#############$$:${ECHO} "$${caudium_enable}" | ${EGREP} -iq "^yes|^true" || exit:' \
		-e 's:/tmp/caudium_pid:/var/run/caudium.pid:' \
		-e '/flags=--with-threads/s:^# ::' \
		-e 's:-www:-${WWWOWN}:' \
		${WRKSRC}/tools/caudium-rc_script.in > ${WRKDIR}/caudium

post-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/caudium ${PREFIX}/etc/rc.d/
	@${RM} ${PREFIX}/caudium/server/base_server/caudium.pike.rej
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/caudium
	@${CAT} ${PKGMESSAGE}

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

.include <bsd.port.post.mk>
