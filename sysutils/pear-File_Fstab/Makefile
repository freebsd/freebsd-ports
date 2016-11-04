# Created by: Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
# $FreeBSD$

PORTNAME=	File_Fstab
PORTVERSION=	2.0.3
CATEGORIES=	sysutils devel pear

MAINTAINER=	joneum@bsdproject.de
COMMENT=	PEAR class to read and write fstab files

USES=	pear

post-extract:
.for file in ${FILES}
	@${REINPLACE_CMD} -e "s|@package_version@|${PORTVERSION}|" ${WRKSRC}/File/${file}
.endfor

.include <bsd.port.mk>
