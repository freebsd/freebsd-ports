# Created by: Josh Gilliam <josh@quick.net>
# $FreeBSD$

PORTNAME=	urlview
PORTVERSION=	0.9
PORTREVISION=	7
CATEGORIES=	textproc www
MASTER_SITES=	ftp://ftp.mutt.org/mutt/contrib/ \
		ftp://ftp.cs.tu-berlin.de/pub/net/mail/mutt/contrib/ \
		ftp://ftp.fu-berlin.de/pub/unix/mail/mutt/contrib/ \
		ftp://ftp.gbnet.net/pub/mutt-international/contrib/ \
		ftp://ftp.gwdg.de/pub/unix/mail/mutt/international/contrib/ \
		http://seis.bris.ac.uk/~mexas/

MAINTAINER=	mexas@bris.ac.uk
COMMENT=	URL extractor/launcher

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
PLIST_FILES=	bin/urlview \
		etc/urlview.conf.sample \
		man/man1/urlview.1.gz
MAKE_ENV=	DESTDIR=${STAGEDIR}

post-patch:
	@${REINPLACE_CMD} -e 's,/etc,${PREFIX}&,' \
		-e 's/url_handler.sh/firefox/' \
		${WRKSRC}/*

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/urlview ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/urlview.man ${STAGEDIR}${MAN1PREFIX}/man/man1/urlview.1
	${INSTALL_DATA} ${WRKSRC}/sample.urlview \
		${STAGEDIR}${PREFIX}/etc/urlview.conf.sample

.include <bsd.port.mk>
