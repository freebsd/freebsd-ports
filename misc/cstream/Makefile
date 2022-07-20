PORTNAME=	cstream
PORTVERSION=	3.2.1
CATEGORIES=	misc
MASTER_SITES=	http://www.cons.org/cracauer/download/

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Like dd(1) tool, precise bandwidth limiting/reporting, fifo, TCP

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/cstream \
		man/man1/cstream.1.gz

post-patch:
	@${REINPLACE_CMD} -e \
		'/^if \[/s| $$CFLAGS | "$$CFLAGS" |' ${WRKSRC}/configure

.include <bsd.port.mk>
