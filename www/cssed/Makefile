# ex:ts=8
# Ports collection makefile for:	cssed
# Date created:			Jul 29, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	cssed
PORTVERSION=	0.2.1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An application to help CSS style sheets creation and maintenance

LIB_DEPENDS=	expat.5:${PORTSDIR}/textproc/expat2

USE_ICONV=	yes
USE_GETTEXT=	yes
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

PLIST_FILES=	bin/cssed share/locale/es/LC_MESSAGES/cssed.mo share/locale/fr/LC_MESSAGES/cssed.mo
MAN1=	cssed.1

post-install:
	@${FIND} ${DATADIR} ! -type d | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${DATADIR} -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}

.include <bsd.port.mk>
