# New ports collection makefile for:	fetchmail
# Version required:     4.3.5
# Date created:		26 Oct 1996
# Whom:			Ville Eerola <ve@sci.fi>
#
# $Id: Makefile,v 1.53 1997/12/15 20:55:27 max Exp $
#

DISTNAME=       fetchmail-4.3.5
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.ccil.org/pub/esr/fetchmail/

MAINTAINER=	ve@sci.fi

GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --enable-opie
CONFIGURE_ENV=  LDFLAGS="${CFLAGS}"
MAN1=		fetchmail.1

.if exists(/usr/lib/libkrb.a) && (defined(MAKE_EBONES) || defined(MAKE_KERBEROS4))
CONFIGURE_ARGS += --with-kerberos=/usr/include/kerberosIV
.endif

FDOC=   ${PREFIX}/share/doc/fetchmail

post-patch:
	@${CP} -f  /usr/include/md5.h ${WRKSRC}

post-install:
	${INSTALL} -d -m 555 -o ${DOCOWN} -g ${DOCGRP} ${FDOC}
	cd ${WRKSRC} && ${INSTALL_DATA} \
	   sample.rcfile FAQ NOTES FEATURES README COPYING \
	   fetchmail-FAQ.html fetchmail-features.html \
	   design-notes.html ${FDOC}

.include <bsd.port.mk>
