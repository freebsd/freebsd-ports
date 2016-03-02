# Created by: Ralf van Dooren <r.vdooren@snow.nl>
# $FreeBSD$

PORTNAME=	rsnapshot
PORTVERSION=	1.4.2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.rsnapshot.org/downloads/

MAINTAINER=	ralfvd@gmail.com
COMMENT=	Filesystem snapshot utility based on rsync(1)

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	rsync:${PORTSDIR}/net/rsync
RUN_DEPENDS=	rsync:${PORTSDIR}/net/rsync \
		p5-Lchown>=0:${PORTSDIR}/sysutils/p5-Lchown

OPTIONS_DEFINE=	DOCS

USES=		perl5
GNU_CONFIGURE=	yes
NO_ARCH=	yes

PORTDOCS=	AUTHORS ChangeLog README.md

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
