PORTNAME=	pam_search_list
PORTVERSION=	0.1
PORTREVISION=	3
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME:S/_/-/g}
DISTNAME=	${PORTNAME:S/_/-/g}-${PORTVERSION}

MAINTAINER=	v.a.popov@gmail.com
COMMENT=	PAM module to search arbitrary file for user
WWW=		https://sourceforge.net/projects/pam-search-list/

USES=		tar:xz uidfix

MAKE_ARGS=	MANDIR="${PREFIX}/share/man/man"

PLIST_FILES=	lib/libpam_search_list.a \
		lib/pam_search_list.so \
		lib/pam_search_list.so.0 \
		share/man/man8/pam_search_list.8.gz

OPTIONS_DEFINE=	PROFILE

PROFILE_MAKE_ENV=	MK_PROFILE=yes
PROFILE_PLIST_FILES=	lib/libpam_search_list_p.a

.include <bsd.port.mk>
