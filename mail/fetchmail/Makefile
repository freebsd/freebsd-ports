# New ports collection makefile for:	fetchmail
# Version required:     3.9.7
# Date created:		26 Oct 1996
# Whom:			Ville Eerola <ve@sci.fi>
#
# $Id: Makefile,v 1.32 1997/06/09 23:49:42 max Exp $
#

DISTNAME=       fetchmail-3.9.7
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.ccil.org/pub/esr/fetchmail/

MAINTAINER=	ve@sci.fi

GNU_CONFIGURE=	yes
CONFIGURE_ENV+= LDFLAGS="${CFLAGS}"
MAN1=		fetchmail.1

FDOC=   ${PREFIX}/share/doc/fetchmail

post-patch:
	cp /usr/include/md5.h ${WRKSRC}

post-install:
	install -d -m 555 -o ${DOCOWN} -g ${DOCGRP} ${FDOC}
	cd ${WRKSRC} && ${INSTALL_DATA} \
		sample.rcfile FAQ fetchmail.FAQ.html ${FDOC}

.include <bsd.port.mk>
