# ex:ts=8
# Ports collection makefile for:	documancer
# Date created:			Oct 27, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	documancer
PORTVERSION=	0.2.4
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	chinsan@FreeBSD.org
COMMENT=	A programmer's documentation reader

BUILD_DEPENDS=	wget:${PORTSDIR}/ftp/wget \
		swish-e:${PORTSDIR}/www/swish-e
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=	2.4
USE_PERL5=	yes
USE_WX=		2.4
WX_COMPS=	mozilla python
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--libdir=${PREFIX}/share

PLIST_FILES=	bin/documancer

post-install:
	@${FIND} ${DATADIR} -type f | ${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${DATADIR} -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}

.include <bsd.port.mk>
