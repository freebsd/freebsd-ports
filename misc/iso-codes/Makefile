# New ports collection makefile for:   iso-codes
# Date created:			02 April 2005
# Whom:				Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	codes
PORTVERSION=	0.45
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_DEBIAN}
MASTER_SITE_SUBDIR=	pool/main/i/${PORTNAME}
PKGNAMEPREFIX=	iso-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Lists of the country, language and currency iso names

BUILD_DEPENDS=	xmlproc_parse:${PORTSDIR}/textproc/py-xml

WRKSRC=		${WRKDIR}/${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}
USE_PYTHON_BUILD=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

DATADIR=	${PREFIX}/share/${PKGNAMEPREFIX}${PORTNAME}

CATALOGS_iso639=\
		aa.mo af.mo am.mo ar.mo az.mo be.mo bg.mo bn.mo br.mo bs.mo \
		byn.mo ca.mo cs.mo cy.mo da.mo de.mo dv.mo el.mo eo.mo es.mo \
		et.mo eu.mo fa.mo fi.mo fo.mo fr.mo ga.mo gez.mo gl.mo gu.mo \
		gv.mo haw.mo he.mo hi.mo hr.mo hu.mo hy.mo id.mo is.mo it.mo \
		iu.mo ja.mo ka.mo kk.mo kl.mo kn.mo ko.mo kok.mo kw.mo ky.mo \
		lt.mo lv.mo mi.mo mk.mo mn.mo mr.mo ms.mo mt.mo nb.mo nl.mo \
		nn.mo no.mo nso.mo oc.mo om.mo pa.mo pl.mo ps.mo pt.mo \
		pt_BR.mo ro.mo ru.mo rw.mo sa.mo sid.mo sk.mo sl.mo so.mo \
		sq.mo sr.mo sv.mo sw.mo syr.mo ta.mo te.mo th.mo ti.mo tig.mo \
		tr.mo tt.mo uk.mo ur.mo uz.mo ve.mo vi.mo wa.mo wal.mo xh.mo \
		zh_CN.mo zh_TW.mo zu.mo
CATALOGS_iso3166=\
		aa.mo af.mo am.mo ar.mo az.mo be.mo bg.mo bn.mo br.mo bs.mo \
		byn.mo ca.mo cs.mo cy.mo da.mo de.mo dv.mo el.mo eo.mo es.mo \
		et.mo eu.mo fa.mo fi.mo fo.mo fr.mo ga.mo gez.mo gl.mo gu.mo \
		gv.mo haw.mo he.mo hi.mo hr.mo hu.mo hy.mo id.mo is.mo it.mo \
		ja.mo ka.mo kk.mo kl.mo kn.mo ko.mo kok.mo kw.mo ky.mo lt.mo \
		lv.mo mi.mo mk.mo mn.mo mr.mo ms.mo mt.mo nb.mo nl.mo nn.mo \
		no.mo nso.mo oc.mo om.mo pa.mo pl.mo ps.mo pt.mo pt_BR.mo \
		ro.mo ru.mo rw.mo sa.mo sk.mo sl.mo so.mo sq.mo sr.mo sv.mo \
		sw.mo ta.mo te.mo th.mo ti.mo tig.mo tk.mo tl.mo tr.mo uk.mo \
		ur.mo uz.mo ve.mo vi.mo wa.mo wal.mo xh.mo zh_CN.mo zh_TW.mo \
		zu.mo
CATALOGS_iso3166_2=\
		af.mo ar.mo az.mo bg.mo br.mo bs.mo ca.mo cs.mo da.mo el.mo \
		eo.mo es.mo et.mo eu.mo fa.mo fi.mo fr.mo ga.mo gl.mo he.mo \
		hr.mo hu.mo id.mo is.mo it.mo ja.mo ko.mo lt.mo lv.mo mi.mo \
		mk.mo mn.mo mt.mo nb.mo nl.mo no.mo nso.mo oc.mo pl.mo pt.mo \
		pt_BR.mo ro.mo ru.mo sk.mo sl.mo sr.mo sv.mo ta.mo th.mo tr.mo \
		uk.mo ve.mo vi.mo wa.mo xh.mo zh_CN.mo zh_TW.mo zu.mo
CATALOGS_iso4217=\
		af.mo ca.mo cs.mo da.mo de.mo el.mo es.mo et.mo fi.mo fr.mo \
		ga.mo gl.mo hr.mo hu.mo it.mo ja.mo ko.mo lt.mo mn.mo ms.mo \
		mt.mo nl.mo nn.mo no.mo pa.mo pl.mo pt.mo pt_BR.mo ru.mo rw.mo \
		sk.mo sl.mo sr.mo sv.mo th.mo tr.mo uk.mo zh_CN.mo zh_TW.mo

post-patch:
	@${REINPLACE_CMD} -e 's|!/usr/bin/python|!${LOCALBASE}/bin/python|g' \
		${WRKSRC}/iso2pot.py ${WRKSRC}/iso2tab.py \
		${WRKSRC}/iso_3166/iso3166tab.py ${WRKSRC}/iso_639/iso639tab.py
	@${REINPLACE_CMD} -e 's|-D|-d|g' \
		${WRKSRC}/iso_3166/Makefile.in ${WRKSRC}/iso_4217/Makefile.in \
		${WRKSRC}/iso_639/Makefile.in

do-install:
.for cat in ${CATALOGS_iso639}
	@${MKDIR} ${PREFIX}/share/locale/${cat:S|.mo||}/LC_MESSAGES
	@${INSTALL_SCRIPT} \
		${WRKSRC}/iso_639/${cat} \
		${PREFIX}/share/locale/${cat:S|.mo||}/LC_MESSAGES/iso_639.mo
.endfor
.for catalog in ${CATALOGS_iso3166}
	@${MKDIR} ${PREFIX}/share/locale/${cat:S|.mo||}/LC_MESSAGES
	@${INSTALL_SCRIPT} \
		${WRKSRC}/iso_3166/${catalog} \
		${PREFIX}/share/locale/${catalog:S|.mo||}/LC_MESSAGES/iso_3166.mo
.endfor
.for catalog in ${CATALOGS_iso3166_2}
	@${MKDIR} ${PREFIX}/share/locale/${catalog:S|.mo||}/LC_MESSAGES
	@${INSTALL_SCRIPT} \
		${WRKSRC}/iso_3166/iso_3166_2/${catalog} \
		${PREFIX}/share/locale/${catalog:S|.mo||}/LC_MESSAGES/iso_3166_2.mo
.endfor
.for catalog in ${CATALOGS_iso4217}
	@${MKDIR} ${PREFIX}/share/locale/${catalog:S|.mo||}/LC_MESSAGES
	@${INSTALL_SCRIPT} \
		${WRKSRC}/iso_4217/${catalog} \
		${PREFIX}/share/locale/${catalog:S|.mo||}/LC_MESSAGES/iso_4217.mo
.endfor
	@${MKDIR} ${PREFIX}/share/xml/iso-codes
	@${INSTALL_SCRIPT} ${WRKSRC}/iso_3166/iso_3166.xml \
		${PREFIX}/share/xml/iso-codes/iso_3166.xml
	@${INSTALL_SCRIPT} ${WRKSRC}/iso_3166/iso_3166_2/iso_3166_2.xml \
		${PREFIX}/share/xml/iso-codes/iso_3166_2.xml
	@${INSTALL_SCRIPT} ${WRKSRC}/iso_4217/iso_4217.xml \
		${PREFIX}/share/xml/iso-codes/iso_4217.xml
	@${INSTALL_SCRIPT} ${WRKSRC}/iso_639/iso_639.xml \
		${PREFIX}/share/xml/iso-codes/iso_639.xml
	@${MKDIR} ${PREFIX}/libdata/pkgconfig
	@${INSTALL_SCRIPT} ${WRKSRC}/iso-codes.pc \
		${PREFIX}/libdata/pkgconfig/iso-codes.pc
	@${MKDIR} ${PREFIX}/share/iso-codes
	@${INSTALL_SCRIPT} ${WRKSRC}/iso_3166/iso_3166.tab \
		${PREFIX}/share/iso-codes
	@${INSTALL_SCRIPT} ${WRKSRC}/iso_3166/iso_3166_2/iso_3166_2.tab \
		${PREFIX}/share/iso-codes
	@${INSTALL_SCRIPT} ${WRKSRC}/iso_4217/iso_4217.tab \
		${PREFIX}/share/iso-codes
	@${INSTALL_SCRIPT} ${WRKSRC}/iso_639/iso_639.tab \
		${PREFIX}/share/iso-codes

.include <bsd.port.mk>
