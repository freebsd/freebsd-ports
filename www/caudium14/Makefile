# New ports collection makefile for:	pike
# Date created:		15 May 2004
# Whom:			kiwi@oav.net
#
# $FreeBSD$
#

PORTNAME=	caudium14
PORTVERSION=	1.4.14
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.caudium.net/caudium/source/ \
		ftp://ftp.oav.net/caudium/source/
DISTNAME=	caudium-${PORTVERSION}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	A free webserver based on the Roxen Challenger 1.3 code base

BUILD_DEPENDS=	pike76:${PORTSDIR}/lang/pike76/
LIB_DEPENDS=	sablot.70:${PORTSDIR}/textproc/sablotron/
RUN_DEPENDS=	lsof:${PORTSDIR}/sysutils/lsof/

USE_BZIP2=	yes
USE_GMAKE=	yes

PIKEVERSION=	7.6.112
SUB_LIST+=	PIKEVERSION="${PIKEVERSION}"

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--without-debug --with-PiXSL --prefix=${PREFIX} \
		 --with-pike=${LOCALBASE}/pike/${PIKEVERSION}/bin/pike
CPPFLAGS+=	-I${WRKSRC}/src/cmods

PLIST_SUB+=	PIKEVERSION=${PIKEVERSION}
CONFLICTS+=	caudium12-[0-9]*

post-patch:
	@${SED} -e 's:@CAUDIUM_SERVERDIR@:${PREFIX}/caudium/server:' \
		-e 's:^#############$$:${ECHO} "$${caudium_enable}" | ${EGREP} -iq "^yes|^true" || exit:' \
		-e 's:/tmp/caudium_pid:/var/run/caudium.pid:' \
		-e '/flags=--with-threads/s:^# ::' \
		-e 's:-www:-${WWWOWN}:' \
		${WRKSRC}/tools/caudium-rc_script.in > ${WRKDIR}/caudium

post-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/caudium ${PREFIX}/etc/rc.d/
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
