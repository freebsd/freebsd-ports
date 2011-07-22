# New ports collection makefile for:	hyphen
# Date created:		2011-06-18
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	hyphen
PORTVERSION=	2.7.1
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	SF/hunspell/Hyphen/2.7/

MAINTAINER=	office@FreeBSD.org
COMMENT=	Library for high quality hyphenation and justification

BUILD_DEPENDS=	gawk:${PORTSDIR}/lang/gawk

USE_GNOME=	gnomehack
USE_LDCONFIG=	yes
USE_PERL5_BUILD=	yes

GNU_CONFIGURE=	yes

USALIASES=	en_AG en_AU en_BS en_BW en_BZ en_CA en_DK en_GB en_GH en_HK \
		en_IE en_IN en_JM en_NA en_NZ en_PH en_SG en_TT en_ZA en_ZW

.for ALIAS in ${USALIASES}
PLIST_FILES+=	share/hyphen/hyph_${ALIAS}.dic
.endfor

post-install:
	@cd ${DATADIR}; \
	for alias in ${USALIASES}; do \
		${LN} -s hyph_en_US.dic hyph_$${alias}.dic ; \
	done

.include <bsd.port.mk>
