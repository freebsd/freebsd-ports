# Ports collection makefile for:  pear-I18Nv2
# Date created:			  01 December 2004
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	I18Nv2
PORTVERSION=	0.11.1
CATEGORIES=	sysutils devel pear

MAINTAINER=	antonio@php.net
COMMENT=	PEAR Internationalization

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PHP=	iconv

FILES=		I18Nv2.php I18Nv2/Locale.php I18Nv2/CommonList.php I18Nv2/Country.php \
		I18Nv2/Language.php I18Nv2/Currency.php I18Nv2/AreaCode.php \
		I18Nv2/Encoding.php I18Nv2/Negotiator.php I18Nv2/DecoratedList.php \
		I18Nv2/DecoratedList/Filter.php I18Nv2/DecoratedList/HtmlSelect.php \
		I18Nv2/DecoratedList/HtmlEntities.php \
		I18Nv2/DecoratedList/HtmlSpecialchars.php \
		I18Nv2/DecoratedList/AfricanCountries.php \
		I18Nv2/DecoratedList/AsianCountries.php \
		I18Nv2/DecoratedList/EuropeanCountries.php \
		I18Nv2/DecoratedList/NorthAmericanCountries.php \
		I18Nv2/DecoratedList/OceanianCountries.php \
		I18Nv2/DecoratedList/SouthAmericanCountries.php I18Nv2/Country/aa.php \
		I18Nv2/Country/af.php I18Nv2/Country/am.php I18Nv2/Country/ar.php \
		I18Nv2/Country/as.php I18Nv2/Country/az.php I18Nv2/Country/be.php \
		I18Nv2/Country/bg.php I18Nv2/Country/bn.php I18Nv2/Country/ca.php \
		I18Nv2/Country/cs.php I18Nv2/Country/cy.php I18Nv2/Country/da.php \
		I18Nv2/Country/de.php I18Nv2/Country/dv.php I18Nv2/Country/dz.php \
		I18Nv2/Country/el.php I18Nv2/Country/en.php I18Nv2/Country/eo.php \
		I18Nv2/Country/es.php I18Nv2/Country/et.php I18Nv2/Country/eu.php \
		I18Nv2/Country/fa.php I18Nv2/Country/fi.php I18Nv2/Country/fo.php \
		I18Nv2/Country/fr.php I18Nv2/Country/ga.php I18Nv2/Country/gl.php \
		I18Nv2/Country/gu.php I18Nv2/Country/gv.php I18Nv2/Country/he.php \
		I18Nv2/Country/hi.php I18Nv2/Country/hr.php I18Nv2/Country/hu.php \
		I18Nv2/Country/hy.php I18Nv2/Country/id.php I18Nv2/Country/is.php \
		I18Nv2/Country/it.php I18Nv2/Country/iu.php I18Nv2/Country/ja.php \
		I18Nv2/Country/ka.php I18Nv2/Country/kk.php I18Nv2/Country/kl.php \
		I18Nv2/Country/km.php I18Nv2/Country/kn.php I18Nv2/Country/ko.php \
		I18Nv2/Country/kw.php I18Nv2/Country/ky.php I18Nv2/Country/lo.php \
		I18Nv2/Country/lt.php I18Nv2/Country/lv.php I18Nv2/Country/mk.php \
		I18Nv2/Country/ml.php I18Nv2/Country/mn.php I18Nv2/Country/mr.php \
		I18Nv2/Country/ms.php I18Nv2/Country/mt.php I18Nv2/Country/nb.php \
		I18Nv2/Country/nl.php I18Nv2/Country/nn.php I18Nv2/Country/om.php \
		I18Nv2/Country/or.php I18Nv2/Country/pa.php I18Nv2/Country/pl.php \
		I18Nv2/Country/ps.php I18Nv2/Country/pt.php I18Nv2/Country/ro.php \
		I18Nv2/Country/ru.php I18Nv2/Country/sa.php I18Nv2/Country/sh.php \
		I18Nv2/Country/sk.php I18Nv2/Country/sl.php I18Nv2/Country/so.php \
		I18Nv2/Country/sq.php I18Nv2/Country/sr.php I18Nv2/Country/sv.php \
		I18Nv2/Country/sw.php I18Nv2/Country/ta.php I18Nv2/Country/te.php \
		I18Nv2/Country/th.php I18Nv2/Country/ti.php I18Nv2/Country/tr.php \
		I18Nv2/Country/tt.php I18Nv2/Country/uk.php I18Nv2/Country/ur.php \
		I18Nv2/Country/uz.php I18Nv2/Country/vi.php I18Nv2/Country/zh.php \
		I18Nv2/Locale/af.php I18Nv2/Locale/cs.php I18Nv2/Locale/da.php \
		I18Nv2/Locale/de.php I18Nv2/Locale/en.php I18Nv2/Locale/es.php \
		I18Nv2/Locale/fr.php I18Nv2/Locale/hu.php I18Nv2/Locale/it.php \
		I18Nv2/Locale/nl.php I18Nv2/Locale/nb.php I18Nv2/Locale/nn.php \
		I18Nv2/Locale/no.php I18Nv2/Locale/pl.php I18Nv2/Locale/pt.php \
		I18Nv2/Locale/ru.php I18Nv2/Locale/sl.php I18Nv2/Locale/Windows.php \
		I18Nv2/Locale/EUR.php I18Nv2/Locale/de_AT.php I18Nv2/Locale/de_DE.php \
		I18Nv2/Locale/el_GR.php I18Nv2/Locale/en_IE.php I18Nv2/Locale/es_ES.php \
		I18Nv2/Locale/fi_FI.php I18Nv2/Locale/fr_BE.php I18Nv2/Locale/fr_FR.php \
		I18Nv2/Locale/fr_LU.php I18Nv2/Locale/fr_MC.php I18Nv2/Locale/it_IT.php \
		I18Nv2/Locale/nl_BE.php I18Nv2/Locale/nl_NL.php I18Nv2/Locale/pt_PT.php \
		I18Nv2/Locale/sv_FI.php I18Nv2/Language/aa.php I18Nv2/Language/af.php \
		I18Nv2/Language/am.php I18Nv2/Language/ar.php I18Nv2/Language/as.php \
		I18Nv2/Language/az.php I18Nv2/Language/be.php I18Nv2/Language/bg.php \
		I18Nv2/Language/bn.php I18Nv2/Language/ca.php I18Nv2/Language/cs.php \
		I18Nv2/Language/cy.php I18Nv2/Language/da.php I18Nv2/Language/de.php \
		I18Nv2/Language/dv.php I18Nv2/Language/dz.php I18Nv2/Language/el.php \
		I18Nv2/Language/en.php I18Nv2/Language/eo.php I18Nv2/Language/es.php \
		I18Nv2/Language/et.php I18Nv2/Language/eu.php I18Nv2/Language/fa.php \
		I18Nv2/Language/fi.php I18Nv2/Language/fo.php I18Nv2/Language/fr.php \
		I18Nv2/Language/ga.php I18Nv2/Language/gl.php I18Nv2/Language/gu.php \
		I18Nv2/Language/gv.php I18Nv2/Language/he.php I18Nv2/Language/hi.php \
		I18Nv2/Language/hr.php I18Nv2/Language/hu.php I18Nv2/Language/hy.php \
		I18Nv2/Language/id.php I18Nv2/Language/is.php I18Nv2/Language/it.php \
		I18Nv2/Language/iu.php I18Nv2/Language/ja.php I18Nv2/Language/ka.php \
		I18Nv2/Language/kk.php I18Nv2/Language/kl.php I18Nv2/Language/km.php \
		I18Nv2/Language/kn.php I18Nv2/Language/ko.php I18Nv2/Language/kw.php \
		I18Nv2/Language/ky.php I18Nv2/Language/lo.php I18Nv2/Language/lt.php \
		I18Nv2/Language/lv.php I18Nv2/Language/mk.php I18Nv2/Language/ml.php \
		I18Nv2/Language/mn.php I18Nv2/Language/mr.php I18Nv2/Language/ms.php \
		I18Nv2/Language/mt.php I18Nv2/Language/nb.php I18Nv2/Language/nl.php \
		I18Nv2/Language/nn.php I18Nv2/Language/om.php I18Nv2/Language/or.php \
		I18Nv2/Language/pa.php I18Nv2/Language/pl.php I18Nv2/Language/ps.php \
		I18Nv2/Language/pt.php I18Nv2/Language/ro.php I18Nv2/Language/ru.php \
		I18Nv2/Language/sa.php I18Nv2/Language/sh.php I18Nv2/Language/sk.php \
		I18Nv2/Language/sl.php I18Nv2/Language/so.php I18Nv2/Language/sq.php \
		I18Nv2/Language/sr.php I18Nv2/Language/sv.php I18Nv2/Language/sw.php \
		I18Nv2/Language/ta.php I18Nv2/Language/te.php I18Nv2/Language/th.php \
		I18Nv2/Language/ti.php I18Nv2/Language/tr.php I18Nv2/Language/tt.php \
		I18Nv2/Language/uk.php I18Nv2/Language/ur.php I18Nv2/Language/uz.php \
		I18Nv2/Language/vi.php I18Nv2/Language/zh.php I18Nv2/Currency/aa.php \
		I18Nv2/Currency/af.php I18Nv2/Currency/am.php I18Nv2/Currency/ar.php \
		I18Nv2/Currency/as.php I18Nv2/Currency/az.php I18Nv2/Currency/be.php \
		I18Nv2/Currency/bg.php I18Nv2/Currency/bn.php I18Nv2/Currency/ca.php \
		I18Nv2/Currency/cs.php I18Nv2/Currency/cy.php I18Nv2/Currency/da.php \
		I18Nv2/Currency/de.php I18Nv2/Currency/dv.php I18Nv2/Currency/dz.php \
		I18Nv2/Currency/el.php I18Nv2/Currency/en.php I18Nv2/Currency/eo.php \
		I18Nv2/Currency/es.php I18Nv2/Currency/et.php I18Nv2/Currency/eu.php \
		I18Nv2/Currency/fa.php I18Nv2/Currency/fi.php I18Nv2/Currency/fo.php \
		I18Nv2/Currency/fr.php I18Nv2/Currency/ga.php I18Nv2/Currency/gl.php \
		I18Nv2/Currency/gu.php I18Nv2/Currency/gv.php I18Nv2/Currency/he.php \
		I18Nv2/Currency/hi.php I18Nv2/Currency/hr.php I18Nv2/Currency/hu.php \
		I18Nv2/Currency/hy.php I18Nv2/Currency/id.php I18Nv2/Currency/is.php \
		I18Nv2/Currency/it.php I18Nv2/Currency/iu.php I18Nv2/Currency/ja.php \
		I18Nv2/Currency/ka.php I18Nv2/Currency/kk.php I18Nv2/Currency/kl.php \
		I18Nv2/Currency/km.php I18Nv2/Currency/kn.php I18Nv2/Currency/ko.php \
		I18Nv2/Currency/kw.php I18Nv2/Currency/ky.php I18Nv2/Currency/lo.php \
		I18Nv2/Currency/lt.php I18Nv2/Currency/lv.php I18Nv2/Currency/mk.php \
		I18Nv2/Currency/ml.php I18Nv2/Currency/mn.php I18Nv2/Currency/mr.php \
		I18Nv2/Currency/ms.php I18Nv2/Currency/mt.php I18Nv2/Currency/nb.php \
		I18Nv2/Currency/nl.php I18Nv2/Currency/nn.php I18Nv2/Currency/om.php \
		I18Nv2/Currency/or.php I18Nv2/Currency/pa.php I18Nv2/Currency/pl.php \
		I18Nv2/Currency/ps.php I18Nv2/Currency/pt.php I18Nv2/Currency/ro.php \
		I18Nv2/Currency/ru.php I18Nv2/Currency/sa.php I18Nv2/Currency/sh.php \
		I18Nv2/Currency/sk.php I18Nv2/Currency/sl.php I18Nv2/Currency/so.php \
		I18Nv2/Currency/sq.php I18Nv2/Currency/sr.php I18Nv2/Currency/sv.php \
		I18Nv2/Currency/sw.php I18Nv2/Currency/ta.php I18Nv2/Currency/te.php \
		I18Nv2/Currency/th.php I18Nv2/Currency/ti.php I18Nv2/Currency/tr.php \
		I18Nv2/Currency/tt.php I18Nv2/Currency/uk.php I18Nv2/Currency/ur.php \
		I18Nv2/Currency/uz.php I18Nv2/Currency/vi.php I18Nv2/Currency/zh.php
TESTS=		I18Nv2_Locale-PHPUnit_Testcase.php
EXAMPLES=	retrieving_locale_conventions.php setting_a_locale.php \
		transform_output_charset.php using_I18Nv2_Country.php \
		using_I18Nv2_DecoratedList.php using_I18Nv2_Language.php \
		using_I18Nv2_Locale.php using_I18Nv2_Negotiator.php
_EXAMPLESDIR=	docs/examples

post-extract:
	@${MKDIR} ${WRKSRC}/${PORTNAME}
	@${MV} ${WRKSRC}/[A-C]* ${WRKSRC}/${PORTNAME}
	@${MV} ${WRKSRC}/De* ${WRKSRC}/${PORTNAME}
	@${MV} ${WRKSRC}/[E-H]* ${WRKSRC}/${PORTNAME}
	@${MV} ${WRKSRC}/[L-S]* ${WRKSRC}/${PORTNAME}

.include <bsd.port.pre.mk>

PHP_VERS=	${PHP_VERSION:S/.//g}

.if defined(PHP_VERS) && ${PHP_VERS} < 406
#IGNORE=		"You need PHP 4.0.6 or later to install PEAR::I18Nv2"
.endif

.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
