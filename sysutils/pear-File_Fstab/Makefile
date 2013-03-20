# Created by: Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
# $FreeBSD$

PORTNAME=	File_Fstab
PORTVERSION=	2.0.3
CATEGORIES=	sysutils devel pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR class to read and write fstab files

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear

#PEAR_CATSRC=	yes

PEAR_AUTOINSTALL=	yes

post-extract:
.for file in ${FILES}
	@${REINPLACE_CMD} -e "s|@package_version@|${PORTVERSION}|" ${WRKSRC}/File/${file}
.endfor

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
