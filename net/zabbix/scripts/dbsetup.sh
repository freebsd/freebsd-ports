#!/bin/sh

{
	echo "create database zabbix; use zabbix;"
	cat mysql/schema.sql data/data.sql
} | mysql ${*}
