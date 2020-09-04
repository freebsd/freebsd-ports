# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	funionfs
PORTVERSION=	0.4.3
CATEGORIES=	sysutils
MASTER_SITES=	http://funionfs.apiou.org/file/
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Union filesystem for the FUSE driver

LICENSE=	GPLv2+

USES=		fuse localbase
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/funionfs man/man1/${PORTNAME}.1.gz

post-patch:
	@${REINPLACE_CMD} -e 's,^struct unionfs_desc,extern &,' \
		${WRKSRC}/control.c

.include <bsd.port.mk>
