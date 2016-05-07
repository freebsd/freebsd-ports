# $FreeBSD$
# To be included by dictionaries ports.

MASTER_SITES?=	GNU/aspell/dict/${DICT}
DISTNAME?=	aspell${DISTVERSION}
PORTVERSION?=	${DISTVERSION:tl:C/cvs/0_/:C/pt_../p/:C/[0-9]?-?[a-z]+-//g:C/([0-9])([a-z])/\1.\2/g:C/:(.)/\1/g:C/[^a-z0-9+]+/./g}

LIB_DEPENDS=	libaspell.so:textproc/aspell

USES+=		gmake tar:bzip2
HAS_CONFIGURE=	yes

PLIST_SUB=	VER=${VER}

.include <bsd.port.pre.mk>
.if exists(${LOCALBASE}/etc/aspell.ver)
. include "${LOCALBASE}/etc/aspell.ver"
.endif
