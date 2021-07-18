# Created by: Martin Matuska <mm@FreeBSD.org>

PORTNAME=	debootstrap
PORTVERSION=	1.0.123
PORTREVISION=	6
CATEGORIES=	sysutils
MASTER_SITES=	DEBIAN
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	trasz@FreeBSD.org
COMMENT=	Install Debian or Ubuntu base system into a directory

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/debian/copyright

RUN_DEPENDS=	wget:ftp/wget \
		bash:shells/bash \
		${LOCALBASE}/bin/grep:textproc/gnugrep \
		gpgv2:security/gnupg \
		${LOCALBASE}/share/keyrings/ubuntu-archive-keyring.gpg:security/ubuntu-keyring

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes
NO_ARCH=	yes
USES=		gmake perl5
USE_PERL5=	run

post-patch:
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},g' \
		${WRKSRC}/Makefile \
		${WRKSRC}/debootstrap
	@${REINPLACE_CMD} -e 's,%%DATADIR%%,${DATADIR},g' \
		${WRKSRC}/Makefile \
		${WRKSRC}/debootstrap
	@${REINPLACE_CMD} -e 's,%%LOCALBASE%%,${LOCALBASE},g' \
		${WRKSRC}/Makefile \
		${WRKSRC}/debootstrap
	@${REINPLACE_CMD} -e 's,gpgv,gpgv2,g' \
		${WRKSRC}/Makefile \
		${WRKSRC}/debootstrap \
		${WRKSRC}/functions
	@${FIND} ${WRKSRC}/scripts -type f | \
		${XARGS} ${REINPLACE_CMD} -e 's,/usr/share/keyrings,${LOCALBASE}/share/keyrings,g'

	# Workaround for bin/255525
	@${REINPLACE_CMD} -e 's,grep,${LOCALBASE}/bin/grep,g' \
		${WRKSRC}/functions

post-install:
	${INSTALL_MAN} ${WRKSRC}/debootstrap.8 \
		${STAGEDIR}${MAN8PREFIX}/man/man8/debootstrap.8

.include <bsd.port.mk>
