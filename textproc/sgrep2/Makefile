PORTNAME=	sgrep2
PORTVERSION=	1.94a
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.cs.helsinki.fi/pub/Software/Local/Sgrep/ \
		LOCAL/jkoshy
DISTNAME=	sgrep-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Grep for structured text like SGML and HTML
WWW=		https://www.cs.helsinki.fi/u/jjaakkol/sgrep.html

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--datadir=${DATADIR}

CONFLICTS=	sgrep-0.*

.include <bsd.port.mk>
