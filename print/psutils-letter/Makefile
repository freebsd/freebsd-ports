DISTNAME=	psutils-1.13
WRKSRC=		$(WRKDIR)/src-1.3
MASTER_SITES=	ftp://ftp.sunet.se/pub/text-processing/postscript/utilities/psutils/
CATEGORIES+=	printing
MAINTAINER=	jmz@FreeBSD.org

pre-install:
	@mkdir -p ${PREFIX}/share/psutils
	@mkdir -p ${PREFIX}/man/man1
	@mkdir -p ${PREFIX}/bin

.include <bsd.port.mk>
