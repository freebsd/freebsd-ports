# New ports collection makefile for:	darkstat
# Date created:				24 February 2002
# Whom:					Anders Nordby <anders@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	darkstat
PORTVERSION=	2.3
CATEGORIES=	net
MASTER_SITES=	http://members.optushome.com.au/emikulic/net/darkstat/ \
		http://yallara.cs.rmit.edu.au/~emikulic/_/

MAINTAINER=	emikulic@optushome.com.au

LIB_DEPENDS=	intl.4:${PORTSDIR}/devel/gettext

GNU_CONFIGURE=	yes

MAN1=	darkstat.1
DOCS=	AUTHORS ChangeLog INSTALL ISSUES README TODO

post-install:
.if !defined(NOPORTDOCS)
	@${INSTALL} -d -m 0755 ${DOCSDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>
