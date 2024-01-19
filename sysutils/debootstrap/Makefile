PORTNAME=	debootstrap
PORTVERSION=	${DEB_VERSION}n${DEB_NMU}
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	DEBIAN
DISTNAME=	${PORTNAME}_${DEB_VERSION}+nmu${DEB_NMU}

MAINTAINER=	nc@FreeBSD.org
COMMENT=	Install Debian or Ubuntu base system into a directory
WWW=		https://wiki.debian.org/Debootstrap

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/debian/copyright

RUN_DEPENDS=	wget:ftp/wget \
		bash:shells/bash \
		${LOCALBASE}/bin/grep:textproc/gnugrep \
		gpgv2:security/gnupg \
		${LOCALBASE}/share/keyrings/ubuntu-archive-keyring.gpg:security/ubuntu-keyring

USES=		gmake perl5
USE_PERL5=	run

MAKE_ENV=	DATADIR="${DATADIR}"
NO_ARCH=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

# The +nmu suffix used by debian for "non maintainer uploads" of a Debian
# native package doesn't play well with our versioning
DEB_VERSION=	1.0.128
DEB_NMU=	2

post-patch:
	@${REINPLACE_CMD} \
		-e 's,%%DATADIR%%,${DATADIR},g' \
		-e 's,%%LOCALBASE%%,${LOCALBASE},g' \
		${WRKSRC}/debootstrap
	@${FIND} ${WRKSRC}/scripts -type f | \
		${XARGS} ${REINPLACE_CMD} -e 's,/usr/share/keyrings,${LOCALBASE}/share/keyrings,g'

	# Workaround for bin/255525
	@${REINPLACE_CMD} -e 's,grep,${LOCALBASE}/bin/grep,g' \
		${WRKSRC}/functions

post-install:
	${INSTALL_MAN} ${WRKSRC}/debootstrap.8 \
		${STAGEDIR}${PREFIX}/share/man/man8/debootstrap.8

.include <bsd.port.mk>
