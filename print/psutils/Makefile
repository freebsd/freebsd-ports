PORTNAME=	psutils
PORTVERSION=	1.17
PORTREVISION=	6
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.dcs.ed.ac.uk/pub/ajcd/ \
		ftp://ftp.knackered.org/pub/psutils/ \
		TEX/obsolete/support/psutils \
		https://ftp.osuosl.org/pub/blfs/conglomeration/psutils/
DISTNAME=	psutils-p17

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Utilities for manipulating PostScript documents
WWW=		http://gershwin.ens.fr/vdaniel/Doc-Locale/Outils-Gnu-Linux/PsUtils/

LICENSE=	PSUTILS
LICENSE_NAME=	PS Utilities License
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libpaper.so:print/libpaper

USES=		perl5
USE_PERL5=	build

MAKEFILE=	Makefile.unix
MAKE_ENV+=	CHMOD="${CHMOD}" \
		DATADIR="${DATADIR}" \
		PERL="${PERL}"
SCRIPTS_ENV+=	CC=${CC} \
		DATADIR=${DATADIR} \
		PAPER=dummy \
		PERL5=${PERL}

WRKSRC=		${WRKDIR}/${PORTNAME}

.include <bsd.port.mk>
