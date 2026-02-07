PORTNAME=	fprobe
PORTVERSION=	1.1
PORTREVISION=	2
CATEGORIES=	net-mgmt
MASTER_SITES=	SF

MAINTAINER=	farrokhi@FreeBSD.org
COMMENT=	Tool that collects network traffic data
WWW=		https://sourceforge.net/projects/fprobe/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:bzip2
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
USE_RC_SUBR=	fprobe

PLIST_FILES=	sbin/fprobe share/man/man8/${PORTNAME}.8.gz
PORTDOCS=	ChangeLog README

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ChangeLog README
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
