# ex:ts=8
# New ports collection makefile for:	fwlogwatch
# Date created:			Nov 20, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	fwlogwatch
PORTVERSION=	0.6
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.kyb.uni-stuttgart.de/boris/sw/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	intl.2:${PORTSDIR}/devel/gettext

INSTALL_TARGET=	install install-config install-i18n
MANCOMPRESSES=	no
MAN8=	fwlogwatch.8
MAKE_ENV=	MKDIR="${MKDIR}"

post-patch:
	@${PERL} -pi -e 's,/etc,${PREFIX}/etc,g; \
		s,/usr/local,${PREFIX},g; \
		s,/usr/share,${PREFIX}/share,g; \
		s,%%LOCALBASE%%,${LOCALBASE},g' \
		${WRKSRC}/Makefile ${WRKSRC}/main.h
	@${PERL} -pi -e "s,/etc,${PREFIX}/etc,g" ${WRKSRC}/${MAN8}

post-install:
	@${INSTALL_SCRIPT} ${FILESDIR}/fwlogwatch.sh.sample ${PREFIX}/etc/rc.d

.include <bsd.port.mk>
