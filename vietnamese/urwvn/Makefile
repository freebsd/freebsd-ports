# New ports collection makefile for:	urwvn
# Date created:		2007/01/27
# Whom:			chinsan
#
# $FreeBSD$
#

PORTNAME=	urwvn
PORTVERSION=	3.04
PORTREVISION=	1
CATEGORIES=	vietnamese x11-fonts
MASTER_SITES=	http://vntex.org/urwvn/download/ LOCAL/chinsan
DISTNAME=	urwvn-${PORTVERSION}-ttf

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Vietnamese version of the standard PostScript fonts from URW++

USE_BZIP2=	yes
NO_BUILD=	yes

TTF=	CMConcrete8v.ttf CMConcreteItalic8v.ttf CMConcreteSlanted8v.ttf \
	CMConcreteSmallCaps8v.ttf bchb8v.ttf bchbi8v.ttf bchr8v.ttf \
	bchri8v.ttf cmbr108v.ttf cmbrbx108v.ttf cmbrsl108v.ttf \
	cmsltl108v.ttf cmtl108v.ttf fplrc8v.ttf putb8v.ttf putbi8v.ttf \
	putr8v.ttf putri8v.ttf txbtt8v.ttf txbttsc8v.ttf txtt8v.ttf \
	txttsc8v.ttf uagd8v.ttf uagdo8v.ttf uagk8v.ttf uagko8v.ttf \
	ubkd8v.ttf ubkdi8v.ttf ubkl8v.ttf ubkli8v.ttf ucrb8v.ttf \
	ucrbo8v.ttf ucrr8v.ttf ucrro8v.ttf ugmm8v.ttf ugmmi8v.ttf \
	ugmr8v.ttf ugmri8v.ttf ugqb8v.ttf uhvb8v.ttf uhvbo8v.ttf \
	uhvr8v.ttf uhvro8v.ttf uncb8v.ttf uncbi8v.ttf uncr8v.ttf \
	uncri8v.ttf uopb8v.ttf uopbi8v.ttf uopr8v.ttf uopri8v.ttf \
	uplb8v.ttf uplbi8v.ttf uplr8v.ttf uplri8v.ttf utmb8v.ttf \
	utmbi8v.ttf utmr8v.ttf utmri8v.ttf uzcmi8v.ttf

do-install:
	@${MKDIR} ${FONTSDIR}
.for i in ${TTF}
	${INSTALL_DATA} ${WRKSRC}/${i} ${FONTSDIR}
.endfor

# This target is only meant to be used by the port maintainer.
ttf-gen:	extract
	@${ECHO_CMD} -n 'TTF='
	@cd ${WRKSRC} && ${FIND} . -name "*.ttf" | cut -f2- -d/ | \
		${SORT} | ${TR} '\n' ' '
	@${ECHO} ""

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/chinese/ttfm/Makefile.ttf"
.include <bsd.port.post.mk>
