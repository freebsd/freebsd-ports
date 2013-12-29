# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

CATEGORIES=	russian www
MASTER_SITES=	http://movable-type.ru/downloads/
DISTNAME=	MTOS-${PORTVERSION}-${PKGNAMEPREFIX:S,-,,}

COMMENT=	Russian localization of the MovableType publishing system

MASTERDIR=	${.CURDIR}/../../www/MT
MT_LANG=	${PKGNAMEPREFIX:S,-,,U}
CONFLICTS=	MT-[2-5].* de-MT-[2-5].* fr-MT-[2-5].* ja-MT-[2-5].*

MT_DOCS_URL=	https://github.com/saahov/movabletype/wiki
MT_UPGRADE_URL=	http://movable-type.ru/wiki/%D0%9E%D0%B1%D0%BD%D0%BE%D0%B2%D0%BB%D0%B5%D0%BD%D0%B8%D0%B5_Movable_Type

.include "${MASTERDIR}/Makefile"
