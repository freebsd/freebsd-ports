# Ports collection makefile for:  pear-Services_GeoNames
# Date created:			  24 Jan 2009
# Whom:				  Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Services_GeoNames
PORTVERSION=	0.2.3
CATEGORIES=	www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	A PHP5 Interface to the GeoNames Public API

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear \
		${PEARDIR}/HTTP/Request2.php:${PORTSDIR}/www/pear-HTTP_Request2
RUN_DEPENDS=	${BUILD_DEPENDS}

FILES=		Services/GeoNames.php  Services/GeoNames/Exception.php
EXAMPLES=	examples1.php
TESTS=		AllTests.php \
		data/test_children.dat data/test_cities.dat \
		data/test_countrycode.dat data/test_countryinfo.dat \
		data/test_countrysubdivision.dat data/test_earthquakes.dat \
		data/test_findnearby.dat data/test_findnearbyplacename.dat \
		data/test_findnearbypostalcodes.dat data/test_findnearbystreets.dat \
		data/test_findnearbyweather.dat data/test_findnearbywikipedia.dat \
		data/test_findnearestaddress.dat data/test_findnearestintersection.dat \
		data/test_get.dat data/test_gtopo30.dat \
		data/test_hierarchy.dat data/test_neighbourhood.dat \
		data/test_neighbours.dat data/test_other_03.dat \
		data/test_other_06.dat data/test_postalcodecountryinfo.dat \
		data/test_postalcodelookup.dat data/test_postalcodesearch.dat \
		data/test_search.dat data/test_siblings.dat \
		data/test_srtm3.dat data/test_timezone.dat \
		data/test_weather.dat data/test_weathericao.dat \
		data/test_wikipediaboundingbox.dat data/test_wikipediasearch.dat \
		setup.php \
		test_children.phpt test_cities.phpt \
		test_countrycode.phpt test_countryinfo.phpt \
		test_countrysubdivision.phpt test_earthquakes.phpt \
		test_findnearby.phpt test_findnearbyplacename.phpt \
		test_findnearbypostalcodes.phpt test_findnearbystreets.phpt \
		test_findnearbyweather.phpt test_findnearbywikipedia.phpt \
		test_findnearestaddress.phpt test_findnearestintersection.phpt \
		test_get.phpt test_gtopo30.phpt \
		test_hierarchy.phpt test_neighbourhood.phpt \
		test_neighbours.phpt test_other_01.phpt \
		test_other_02.phpt test_other_03.phpt \
		test_other_04.phpt test_other_05.phpt \
		test_other_06.phpt test_other_07.phpt \
		test_postalcodecountryinfo.phpt test_postalcodelookup.phpt \
		test_postalcodesearch.phpt test_search.phpt \
		test_siblings.phpt test_srtm3.phpt \
		test_timezone.phpt test_weather.phpt \
		test_weathericao.phpt test_wikipediaboundingbox.phpt \
		test_wikipediasearch.phpt

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
