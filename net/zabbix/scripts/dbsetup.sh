#!/bin/sh

echo "create database zabbix;" | mysql
cat mysql/schema.sql | mysql zabbix
cat data/data.sql | mysql zabbix
