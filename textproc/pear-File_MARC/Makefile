# Ports collection makefile for:  pear-File_MARC
# Date created:			  Feb 21, 2011
# Whom:				  Wen Heping <wen@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	File_MARC
PORTVERSION=	0.6.2
CATEGORIES=	textproc pear

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Parse, modify, and create MARC records

FILES=		File/MARC.php \
		File/MARCBASE.php \
		File/MARCXML.php \
		File/MARC/Control_Field.php \
		File/MARC/Data_Field.php \
		File/MARC/Exception.php \
		File/MARC/Field.php \
		File/MARC/List.php \
		File/MARC/Record.php \
		File/MARC/Subfield.php
TESTS=		bad_example.mrc bad_example.xml \
		bigarchive.xml example.mrc \
		marc_001.phpt marc_002.phpt \
		marc_003.phpt marc_004.phpt \
		marc_005.phpt marc_006.phpt \
		marc_007.phpt marc_008.phpt \
		marc_009.phpt marc_010.phpt \
		marc_011.phpt marc_012.phpt \
		marc_013.phpt marc_014.phpt \
		marc_015.phpt marc_016.phpt \
		marc_017.phpt marc_018.phpt \
		marc_16783.phpt \
		marc_field_001.phpt marc_field_002.phpt \
		marc_field_003.phpt marc_field_004.phpt \
		marc_record_001.phpt \
		marc_subfield_001.phpt marc_subfield_002.phpt \
		marc_xml_001.phpt marc_xml_002.phpt \
		marc_xml_003.phpt marc_xml_004.phpt \
		marc_xml_005.phpt marc_xml_006.phpt \
		marc_xml_007.phpt marc_xml_008.phpt \
		marc_xml_009.phpt \
		marc_xml_16642.phpt \
		marc_xml_rsinger.phpt \
		music.mrc \
		music.xml \
		onerecord.xml \
		sandburg.mrc \
		sandburg.xml \
		skipif.inc \
		xmlescape.mrc
EXAMPLES=	example.mrc marc_yaz.php \
		read.php subfields.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
