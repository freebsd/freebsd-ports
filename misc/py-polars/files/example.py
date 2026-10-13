import polars as pl

# Create a DataFrame
data = {'Name': ['Alice', 'Bob', 'Charlie', 'David'],
        'Age': [25, 30, 22, 28],
        'City': ['New York', 'London', 'Paris', 'Tokyo']}

df = pl.DataFrame(data)

# Print the DataFrame
print("Original DataFrame:")
print(df)

# Select columns
names_ages = df.select(['Name', 'Age'])
print("\nSelected columns (Name and Age):")
print(names_ages)

# Filter rows
adults = df.filter(pl.col('Age') >= 25)
print("\nRows where Age is greater than or equal to 25:")
print(adults)

# Add a new column
df = df.with_columns(pl.col('Age') * 2).rename({'Age': 'Double_Age'})
print("\nDataFrame with a new column (Double_Age):")
print(df)

# Group by and aggregate
average_age_by_city = df.group_by('City').agg(pl.mean('Double_Age'))
print("\nAverage Double_Age by City:")
print(average_age_by_city)
