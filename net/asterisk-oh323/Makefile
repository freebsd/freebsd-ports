# New ports collection makefile for:	asterisk-oh323
# Date created:		17 Jun 2005
# Whom:			Andriy Pylypenko <bamby@portaone.com>
#
# $FreeBSD$
#

PORTNAME=	asterisk-oh323
PORTVERSION=	0.7.3.1
PORTREVISION=	4
CATEGORIES=	net
MASTER_SITES=	http://www.b2bua.org/chrome/site/

MAINTAINER=	bamby@sippysoft.com
COMMENT=	A H.323 support module for the Asterisk soft PBX

BUILD_DEPENDS= 	${LOCALBASE}/sbin/asterisk:${PORTSDIR}/net/asterisk14
LIB_DEPENDS= 	pt_r.1:${PORTSDIR}/devel/pwlib\
	    	h323_r.1:${PORTSDIR}/net/openh323

USE_GMAKE=	yes
MAKE_ENV=	MKDIR="${MKDIR}" \
		PWLIBDIR=${LOCALBASE}/share/pwlib \
		OPENH323DIR=${LOCALBASE}/share/openh323 \
		CPP="${CXX}" \
		SYSLIBDIR=${LOCALBASE}/lib

.include <bsd.port.pre.mk>

# XXX: bsd.gcc.mk now defines CPP
CPP=		"${CXX}"

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

pre-configure:
	if ${GREP} -sq fixup_codecs ${LOCALBASE}/include/asterisk/channel.h; \
	then \
		${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/codecnego.diff; \
	fi

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
