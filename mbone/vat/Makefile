# New ports collection makefile for:	vat
# Version required:	4.0b2
# Date created:		2 November 1996
# Whom:			fenner
#
# $Id: $
#

DISTNAME=	vat-4.0b2
CATEGORIES+=	mbone
MASTER_SITES=	ftp://ftp.ee.lbl.gov/conferencing/vat/alpha-test/
DISTFILES=	vatsrc-4.0b2.tar.gz

MAINTAINER=	fenner@FreeBSD.ORG

GSM_DIR=	${PORTSDIR}/audio/gsm

DEPENDS=	${GSM_DIR}
LIB_DEPENDS=	tk41:${PORTSDIR}/x11/tk41 \
		gsm:${GSM_DIR}

USE_X11=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gsm=${GSM_DIR}/work/gsm-1.0-pl10

INSTALL_TARGET=	install install-man

post-install:
	strip ${PREFIX}/bin/vat
	${COMPRESS_MAN} ${PREFIX}/man/man1/vat.1

.include <bsd.port.mk>
