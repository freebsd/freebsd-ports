# New ports collection makefile for:	fetchmail
# Version required:     3.9.6
# Date created:		26 Oct 1996
# Whom:			Ville Eerola <ve@sci.fi>
#
# $Id: Makefile,v 1.30 1997/05/20 03:49:29 max Exp $
#

DISTNAME=       fetchmail-3.9.6
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.ccil.org/pub/esr/fetchmail/

MAINTAINER=	ve@sci.fi

GNU_CONFIGURE=	yes
CONFIGURE_ENV+= LDFLAGS="${CFLAGS}"
MAN1=		fetchmail.1

FDOC=   ${PREFIX}/share/doc/fetchmail

post-install:
	install -d -m 555 -o ${DOCOWN} -g ${DOCGRP} ${FDOC}
	cd ${WRKSRC} && ${INSTALL_DATA} \
		sample.rcfile FAQ fetchmail.FAQ.html ${FDOC}

.include <bsd.port.mk>
