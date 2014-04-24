# Created by: Anders Nordby <anders@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pwman
PORTVERSION=	0.4.0
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	anders@FreeBSD.org
COMMENT=	Console password management application based on gpg(me)

LIB_DEPENDS=	libxml2.so:${PORTSDIR}/textproc/libxml2
RUN_DEPENDS=	gpgv:${PORTSDIR}/security/gnupg1

GNU_CONFIGURE=	yes

MAN1=		pwman.1

PLIST_FILES=	bin/convert_pwdb bin/pwdb2csv bin/pwman

PORTDOCS=	AUTHORS COPYING ChangeLog README TODO

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/gpg|${LOCALBASE}/bin/gpg|g' ${WRKSRC}/src/options.c

.if !defined(NOPORTDOCS)
post-install:
	@${INSTALL} -d -m 0755 ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.include <bsd.port.mk>
