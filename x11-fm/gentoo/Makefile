# New ports collection makefile for:	gentoo
# Date created:				12 August 2001
# Whom:					Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	gentoo
PORTVERSION=	0.11.17
CATEGORIES=	x11-fm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	anders@fix.no

LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext

USE_GTK=	yes

MAN1=		gentoo.1

DOCS=		BUGS CONFIG-CHANGES CREDITS NEWS README README.NLS \
		README.gtkrc TODO

GNU_CONFIGURE=	yes

post-patch:
	${PERL} -pi -e "s@icons@${PREFIX}/share/gentoo/icons@g" \
		${WRKSRC}/gentoorc.in

post-install:
	${INSTALL_MAN} ${WRKSRC}/docs/gentoo.1x ${PREFIX}/man/man1/gentoo.1
.if !defined(NOPORTDOCS)
	${CP} -R ${WRKSRC}/docs ${PREFIX}/share/doc/gentoo
	${RM} ${PREFIX}/share/doc/gentoo/gentoo.1x
	${CHMOD} -R a+r,+X ${PREFIX}/share/doc/gentoo
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/gentoo
.endfor
.endif

.include <bsd.port.mk>
