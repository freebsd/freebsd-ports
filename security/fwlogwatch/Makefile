# ex:ts=8
# New ports collection makefile for:	fwlogwatch
# Date created:			Nov 20, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	fwlogwatch
PORTVERSION=	0.5.1
CATEGORIES=	security
MASTER_SITES=	http://www.kyb.uni-stuttgart.de/boris/sw/

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	autob5:${PORTSDIR}/chinese/autoconvert
LIB_DEPENDS=	intl:${PORTSDIR}/devel/gettext

INSTALL_TARGET=	install install-i18n
MANCOMPRESSES=	no
MAN8=	fwlogwatch.8

post-patch:
	@${PERL} -pi -e "s,%%LOCALBASE%%,${LOCALBASE},g ; \
		s,/etc,${PREFIX}/etc,g ; \
		s,/usr/local,${PREFIX},g ; \
		s,/usr/share,${PREFIX}/share,g" ${WRKSRC}/Makefile
	@${PERL} -pi -e "s,/etc,${PREFIX}/etc,g ; \
		s,/usr/share,${PREFIX}/share,g ; \
		s,/usr/local,${PREFIX},g" ${WRKSRC}/main.h
	@${PERL} -pi -e "s,/etc,${PREFIX}/etc,g" ${WRKSRC}/${MAN8}

.include <bsd.port.mk>
