# Ports collection makefile for:  pear-File_Fstab
# Date created:			  09 March 2005
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	File_Fstab
PORTVERSION=	2.0.2
CATEGORIES=	sysutils devel pear

MAINTAINER=	antonio@php.net
COMMENT=	PEAR class to read and write fstab files

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	File
FILES=		Fstab.php Fstab/Entry.php
EXAMPLES=	example.php
_EXAMPLESDIR=	.

post-extract:
	@${MKDIR} ${WRKSRC}/Fstab
	@${MV} ${WRKSRC}/Entry.php ${WRKSRC}/Fstab
.for file in ${FILES}
	@${REINPLACE_CMD} -e "s|@package_version@|${PORTVERSION}|" ${WRKSRC}/${file}
.endfor

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
