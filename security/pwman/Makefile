# New ports collection makefile for:	pwman
# Date created:				23 June 2002
# Whom:					Anders Nordby <anders@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pwman
PORTVERSION=	0.3.2
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	anders@FreeBSD.org
COMMENT=	Console password management application based on gpg(me)

LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2
RUN_DEPENDS=	gpg:${PORTSDIR}/security/gnupg

GNU_CONFIGURE=	yes

MAN1=	pwman.1

DOCS=	AUTHORS COPYING ChangeLog README TODO

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/gpg|${LOCALBASE}/bin/gpg|g' ${WRKSRC}/src/misc.c

.if !defined(NOPORTDOCS)
post-install:
	@${INSTALL} -d -m 0755 ${DOCSDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>
