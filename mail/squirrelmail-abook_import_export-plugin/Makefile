# Created by: Scott Lambert <lambert@lambertfam.org>
# $FreeBSD$

PORTNAME=	abook_import_export
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	mail www
DISTNAME=	${PORTNAME:S/-/_/}-${PORTVERSION}-1.4.4
DIST_SUBDIR=	squirrelmail

MAINTAINER=	lambert@lambertfam.org
COMMENT=	Allows for the importing of addressbooks from a CSV (comma separated values) file

SQUIRREL_PLUGIN_NAME=	${PORTNAME:S/-/_/}

NO_STAGE=	yes

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../squirrelmail/bsd.squirrelmail.mk"
.include <bsd.port.post.mk>
