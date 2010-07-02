# New ports collection makefile for:	ru-MT
# Date created:	   01 Jun 2010
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	MT
CATEGORIES=	russian www
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	ru-
DISTNAME=	MTOS-${PORTVERSION}-ru

COMMENT=	Russian localization of the MovableType publishing system

PROJECTHOST=	movabletype
MASTERDIR=	${.CURDIR}/../../www/${PORTNAME}

MT_LANG=	ru
CONFLICTS=	MT-[2-5].* ja-MT-[2-5].* fr-MT-[2-5].* de-MT-[2-5].* \
		es-MT-[2-5].* nl-MT-[2-5].*

MT_DOCS_URL=	http://movable-type.ru/wiki/
MT_UPGRADE_URL=	http://movable-type.ru/wiki/%D0%9E%D0%B1%D0%BD%D0%BE%D0%B2%D0%BB%D0%B5%D0%BD%D0%B8%D0%B5_Movable_Type

.include "${MASTERDIR}/Makefile"
