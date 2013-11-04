# $FreeBSD$
# To be included by dictionaries ports.

MASTER_SITES?=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR?=	aspell/dict/${DICT}
DISTNAME?=	aspell${DISTVERSION}
PORTVERSION?=	${DISTVERSION:L:C/cvs/0_/:C/pt_../p/:C/[0-9]?-?[a-z]+-//g:C/([0-9])([a-z])/\1.\2/g:C/:(.)/\1/g:C/[^a-z0-9+]+/./g}

LIB_DEPENDS=	libaspell.so:${PORTSDIR}/textproc/aspell

USES+=		gmake
USE_BZIP2=	yes
HAS_CONFIGURE=	yes

PLIST_SUB=	VER=${VER}

.include <bsd.port.pre.mk>
.if exists(${LOCALBASE}/etc/aspell.ver)
. include "${LOCALBASE}/etc/aspell.ver"
.endif
