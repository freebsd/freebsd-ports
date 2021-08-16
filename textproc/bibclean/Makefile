PORTNAME=	bibclean
DISTVERSION=	3.06
CATEGORIES=	textproc
MASTER_SITES=	http://ftp.math.utah.edu/pub//bibclean/

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Prettyprinter, portability verifier, and syntax checker for BibTeX

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:xz

GNU_CONFIGURE=	yes

MAKE_ARGS=	mandir=${PREFIX}/share/man/man1

PLIST_SUB=	VERSION=${DISTVERSION}

.include <bsd.port.mk>
