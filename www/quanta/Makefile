# New ports collection makefile for:	Quanta+
# Date created:				19 May 2000
# Whom:					Will Andrews <will@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	quanta
PORTVERSION= 	2.0p1
CATEGORIES=	www kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-2.0-pr1
.if !defined(NO_PORTDOCS)
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		css.tar.bz2 \
		html.tar.bz2 \
		javascript.tar.bz2 \
		php.tar.bz2
.endif

MAINTAINER=	jeremy@external.org

LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext

WRKSRC=         ${WRKDIR}/${PORTNAME}

USE_KDELIBS_VER=2
USE_XPM=	yes
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --with-extra-includes=${LOCALBASE}/include \
		--disable-closure
USE_GMAKE=	yes

DOCS=		css html javascript php

pre-configure:
	@${PERL} -pi -e "s#lqt #lqt2 #g" ${WRKSRC}/quanta/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
.for doc in ${DOCS}
	cd ${WRKDIR}/${doc} && \
		${CP} -R ${doc} ${doc}.docrc ${PREFIX}/share/apps/quanta/doc
.endfor
	${CHOWN} -R root:wheel ${PREFIX}/share/apps/quanta/doc
	find ${PREFIX}/share/apps/quanta/doc -type f | xargs ${CHMOD} 444
.endif
	
.include <bsd.port.mk>
