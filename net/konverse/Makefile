# New ports collection makefile for:	konverse
# Date created:				30 May 2001
# Whom:				Hye-Shik Chang <perky@python.or.kr>
#
# $FreeBSD$
#

PORTNAME=	konverse
PORTVERSION=	0.2
CATEGORIES=	net kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	perky@fallin.lv

USE_KDELIBS_VER=2
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

CONFIGURE_ARGS+=--with-extra-includes=${LOCALBASE}/include \
		--x-includes=${X11BASE}/include \
		--x-libraries=${X11BASE}/lib

REPATCH=	cd ${WRKSRC} && ${SED}
REPATCHSUBST=	-e 's/libqt\./lib${QTNAME}\./' \
		-e 's/-lqt/-l${QTNAME}/' \
		-e 's/\(LDADD.*\)-ldl/\1/' \
		-e 's/\(QDateTime.*\)timezone/\1local-\>tm_gmtoff/g'
REPATCHFILES=	configure ${PORTNAME}/Makefile.in ${PORTNAME}/jabbercore.cpp
TMPSUFFIX=	.temp

pre-patch:
.for file in ${REPATCHFILES}
	${REPATCH} ${REPATCHSUBST} ${file} > ${file}${TMPSUFFIX} && \
		${CAT} ${file}${TMPSUFFIX} > ${file}
.endfor

.include <bsd.port.mk>
